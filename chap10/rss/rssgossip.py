# Copyright (C) 2019 by Seiichi Nukayama
#
# ---------- original copyright --------------------------------------------
# Copyright (C) 2011 by D+D Griffiths
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
import urllib
import os
import re
import sys
import string
import unicodedata
import getopt
from xml.dom import minidom

def usage():
    print("Usage:\npython rssgossip.py [-uph] <search-regexp>")

try:
    opts, args = getopt.getopt(sys.argv[1:], "uph", ["urls", "prlist","help"])
except getopt.GetoptError, err:
    print str(err)
    usage()
    sys.exit(2)

include_urls = False
prlist = False
for o, a in opts:
    if o == "-u":
        include_urls = True
    elif o == "-p":
        prlist = True
    elif o in ("-h", "--help"):
        usage()
        sys.exit()
    else:
        assert False, "unhandled option"

# print(args[0])

searcher = re.compile(args[0].decode('utf-8'), re.IGNORECASE)
for url in string.split(os.environ['RSS_FEED']):
    print("url: %s" % url)
    feed = urllib.urlopen(url)
    try:
        dom = minidom.parse(feed)
        forecasts = []
        for node in dom.getElementsByTagName('title'):
            txt = node.firstChild.wholeText
            if prlist:
                prtxt = txt.encode('utf-8', 'ignore')
                print("> %s" % prtxt)
            if searcher.search(txt):
                txt = unicodedata.normalize('NFKC', txt).encode('utf-8', 'ignore')
                print(txt)
                if include_urls:
                    p = node.parentNode
                    link = p.getElementsByTagName('link')[0].firstChild.wholeText
                    print("\t%s" % link.encode('utf-8', 'ignore'))
    except:
        sys.exit(1)
