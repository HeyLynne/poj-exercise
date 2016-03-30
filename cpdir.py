import shutil
for i in range(0,1300):
	dname='experienceapi_client'+str(i)
	shutil.copytree('D:\\mine_project\\xAPI\\experienceapi_client','D:\\mine_project\\xAPI\\cilent\\'+dname,False,None)
	print i
print "finished"