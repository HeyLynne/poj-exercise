#encoding=utf8
import sys
import requests
import time
import string

def _encode_multipart(params_dict):
    boundary = '----%s' % hex(int(time.time() * 10000000))
    data = []
    for k, v in params_dict.items():
		data.append('--%s' % boundary)
		if hasattr(v, 'read'):
			filename = getattr(v, 'name', '')
			content = v.read()
			decoded_content = content.decode('ISO-8859-1')
			data.append('Content-Disposition: form-data; name="%s"; filename="hidden"' % k)
			data.append('Content-Type: application/octet-stream\r\n')
			data.append(decoded_content)
		else:
			data.append('Content-Disposition: form-data; name="%s"\r\n' % k)
			data.append(v if isinstance(v, str) else v.decode('utf-8'))
    data.append('--%s--\r\n' % boundary)
    return '\r\n'.join(data), boundary

#login_url="http://www.mooc.buaa.edu.cn"
login_url = 'http://10.2.13.251:12306/admin/'
usradd_url='http://10.2.13.251:12306/admin/auth/user/add/'
client=requests.session()
client.get(login_url)
csrf_token=client.cookies['csrftoken']
hed={'X-CSRFToken':csrf_token,'Refer':'http://10.2.13.251:12306/admin/','User-Agent':'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36','Content-Type':'application/x-www-form-urlencoded'}
udata={'csrfmiddlewaretoken':csrf_token,'username':'db_owner','password':'db_owner_lrs123','this_is_the_login_form':1,'next':'/admin/'}
r=client.post(login_url,data=udata,headers=hed)

for i in range(0,1300):
	client.get(usradd_url)
	csrf_token1=client.cookies['csrftoken']
	username='test'+str(i)
	print username
	fdata={'csrfmiddlewaretoken':csrf_token,'username':username,'password1':'123456','password2':'123456','_save':'Save'}
	rfdata,boundary=_encode_multipart(fdata)
	nbdry='multipart/form-data;boundary='+boundary
	hed1={'X-CSRFToken':csrf_token,'Refer':'http://10.2.13.251:12306/admin/','User-Agent':'Mozilla/5.0 (Windows NT 6.3; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/46.0.2490.80 Safari/537.36','Content-Type':nbdry}
	re=client.post(usradd_url,data=rfdata.encode('ISO-8859-1'),headers=hed1)
	print re.status_code