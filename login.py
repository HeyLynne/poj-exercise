#!/usr/bin/env python
import urllib2,urllib,cookielib,string,random

def randomString(length):
    return ''.join(random.choice(string.letters + string.digits) for i in xrange(length))

XCSRFToken=''.join(randomString(24))
XCSRF2Cookie = 'csrf2_token_%s' % ''.join(randomString(8))
XCSRF2Token = ''.join(randomString(24))
cookie = "csrftoken=%s; %s=%s" % (XCSRFToken, XCSRF2Cookie, XCSRF2Token)
login_url="http://www1.mooc.buaa.edu.cn/login_ajax"
login_params={'email':'lion19930924@163.com','password':'20111liu'}
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.57 Safari/537.36','X-CSRFToken':XCSRFToken,"X-CSRF2-Cookie": XCSRF2Cookie,"X-CSRF2-Token": XCSRF2Token,"Cookie": cookie}
print (headers)
req=urllib2.Request(login_url,urllib.urlencode(login_params),headers=headers)
response=urllib2.urlopen(req)
print(response)
for line in open('D:\\thread.txt','r'):
    print(line)