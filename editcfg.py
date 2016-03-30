import sys,os
for i in range(0,1300):
	fname='D:\\mine_project\\xAPI\\cilent\\experienceapi_client'+str(i)+'\\1.0\\original_prototypes\\config.js'
	fr=open(fname,'r')
	lines=fr.readlines()
	lines[2]='Config.user = "test'+str(i)+'";'
	lines[4]='Config.actor = { "mbox":"mailto:test'+str(i)+'@example.com", "name":"test'+str(i)+'", "objectType": "Agent"};'
	fr.close()
	fw=open(fname,'w')
	fw.writelines(lines)
	print i
print "finished"

