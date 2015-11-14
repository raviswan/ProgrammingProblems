lottery_list=[ "1", "42", "100848", "4938532894754", "1234567", "472844278465445",
"5698157156", "4933187657" ,"4933187652", "49331876521" , "04933176521","12345645231137"]

#lottery_list=["4933187652"]
valid_range = range(1,60)

				#Lottery	#Single		#Double  
				#Length		#Digits		#Digits
						   	#Allowed	#Allowed		
digit_count_map={	
					7:		(7,			0), 
					8:		(6,			1),
					9:		(5,			2),
					10:		(4,			3), 
					11:		(3,			4),
					12:		(2,			5),
					13:		(1,			6),
					14:		(0,			7)
				}

def is_duplicate_present(x,arg):
	"""
	Returns True if a duplicate of x is present in "arg" list. Else return false
	"""
	arg_cpy=list(arg)
	arg_cpy.remove(x)
	if x in arg_cpy:
		return True
	return False


def parse_lottery_ticket(str,length):
	"""
	Parses the lottery ticket passed as a string. The length of the string determines
	how many single digit entries (stored in "single_digit_count" ) and double digit
	entries (stored in "double_digit_count") can be present in the lotteryticket. 
	The max allowed values for a given length is stored in "digit_count_map"
	(above). The "single_digit_list" stores all the single digits in the passed
	string. The "double_digit_list" stores all double digits in sequence starting
	from first position. For e.g. "123456" will be stored as [12,23,34,45,56,6]
	We loop through the length of the string looking for double digits in 
	range [1-59]until we are out of "double_digit_count". 
	If we encounter a duplicate along the way,we split that and check for a valid 
	single digit. Once we are out of possible two digit entries, we look for 
	non-duplicate single digit entries to make up the lottery ticket. By the time 
	we exit the while loop, if we are left with a list of length 7,it's a valid 
	lottery ticket. Else return empty list.
	"""
	lottery_ticket=[]
	single_digit_list=[str[i] for i in range(0,len(str))]
	double_digit_list=[str[i:i+2] for i in range(0,len(str))]
	dim = digit_count_map[length]
	single_digit_count = dim[0]
	double_digit_count = dim[1]
	i=0
	max_length = len(single_digit_list)
	while(i<max_length):
		if( (double_digit_count>0) and ((i+1)<max_length) ):
			entry1 = double_digit_list[i]
			entry2 = double_digit_list[i+1]
			#scenario 1
			if (int(entry1) in valid_range and int(entry2) not in valid_range):
				if( entry1 not in lottery_ticket):
					lottery_ticket += [entry1]
					double_digit_count -= 1
					i += 2
					print lottery_ticket
				else:
					print "Case1a:duplicate of %r not allowed"%(entry1)
					print lottery_ticket
					break
			#scenario 2
			elif (int(entry1) not in valid_range and int(entry2) in valid_range):
				if(single_digit_list[i] not in lottery_ticket\
				and (int(single_digit_list[i]) in valid_range)\
				and entry2 not in lottery_ticket):
					if (single_digit_count>0):
						lottery_ticket += [single_digit_list[i],entry2]
						single_digit_count -= 1
						double_digit_count -= 1
						i += 3
						print lottery_ticket
					else:
						print "2a: single digit max reached. cant add %r"%single_digit_list[i]
						print lottery_ticket
						break
				else:
					print "Case2b: One of  %r or %r is a duplicate"%(single_digit_list[i],entry2)
					print lottery_ticket
					break
			#scenario 3
			elif (int(entry1) not in valid_range and int(entry2) not in valid_range):	
				if (single_digit_count>=2):
					if (single_digit_list[i]  not in lottery_ticket) \
					and (int(single_digit_list[i]) in valid_range) \
					and  (single_digit_list[i+1] not in lottery_ticket)\
					and (int(single_digit_list[i+1]) in valid_range):
						lottery_ticket += [single_digit_list[i], single_digit_list[i+1]]
						single_digit_count -= 2
						i += 2
						print lottery_ticket
					else:
						print "Case3a: Invalid OR Duplicate of %r or %r not allowed"\
						%(single_digit_list[i],single_digit_list[i+1])
						print lottery_ticket
						break
				else:
					print "Case 3b:two successive numbers %r %r not in range 59\
					 can't be split either"%(entry1, entry2)
					print lottery_ticket
					break
			#scenario 4
			elif (int(entry1) in valid_range and int(entry2) in valid_range):
				if (i+2) < len(single_digit_list):
					temp = double_digit_list[i+2]
					if (int(temp) in valid_range):
						if (temp not in lottery_ticket):
							#if temp is last entry with single digit ,
							# it will still be taken care of here
							lottery_ticket +=[entry1]
							double_digit_count -= 1
							if (double_digit_count>0 or single_digit_count>0):
								lottery_ticket += [temp]
								double_digit_count -= 1
								i += 4
								print lottery_ticket
							else:
								print "Case 4a: out of both single and double digit\
								 max for entry=%r"%temp
								print lottery_ticket
								break
						else:
							print"case 4b:This duplicate %r not allowed"%temp
							print lottery_ticket
							break
					elif (int(temp) not in valid_range):
						if(single_digit_count>0):
							#Three digits have to be split into a 2digit and 1digit\
							#..How to split? The last condition need to be checked further
							if (int(single_digit_list[i]) in valid_range) \
							and (single_digit_list[i] not in lottery_ticket)\
							and (entry2 not in lottery_ticket) \
							and (is_duplicate_present(entry2,double_digit_list)==False):
								lottery_ticket +=[single_digit_list[i],entry2]
								double_digit_count -= 1
								single_digit_count -= 1
								i += 3
								print lottery_ticket

							elif (entry1 not in lottery_ticket) \
							and (int(single_digit_list[i+2]) in valid_range) \
							and (single_digit_list[i+2] not in lottery_ticket) \
							and (is_duplicate_present(entry1,double_digit_list)==False):
								lottery_ticket +=[entry1,single_digit_list[i+2]]
								double_digit_count -= 1
								single_digit_count -= 1
								i += 3
								print lottery_ticket
							else:
								print "Case 4c: Both 2-1 combo have issues"
								print lottery_ticket
								break
						else:
							print "Case 4b: out of single digit max for entry=%r"%single_digit_list[i]
							print lottery_ticket
							break
				#last pair of entries. It can be one double digit or 2 single digit
				else:
					if(double_digit_count>0):
						if entry1 not in lottery_ticket:
							lottery_ticket += [entry1]
							double_digit_count -= 1
							i += 2
						#split last two digit and see if you can add
						else:
							if (single_digit_count > 1) \
							and (single_digit_count[i] not in lottery_ticket)\
							and (int(single_digit_list[i]) in valid_range)\
							and (single_digit_list[i+1] not in lottery_ticket)\
							and (int(single_digit_list[i+1]) in valid_range):
								lottery_ticket += [single_digit_count[i],single_digit_count[i+1]]
								single_digit_count -= 2
								i += 2
							else:
								print "last pair is invalid"
								break

					elif (single_digit_count > 1) \
					and (single_digit_count[i] not in lottery_ticket)\
					and (int(single_digit_list[i]) in valid_range)\
					and (single_digit_list[i+1] not in lottery_ticket)\
					and (int(single_digit_list[i+1]) in valid_range):
						lottery_ticket += [single_digit_count[i],single_digit_count[i+1]]
						single_digit_count -= 2
						i += 2
					else:
						print "last pair %r %r can't be added"%(single_digit_list[i],single_digit_list[i+1])
						break

		#for single-digit-only cases or when out of max double digits allowed
		else:
			if((single_digit_count>0) and (int(single_digit_list[i]) in valid_range)):
				if single_digit_list[i] not in lottery_ticket:
					lottery_ticket += [single_digit_list[i]]
					single_digit_count -= 1
					i += 1
					print lottery_ticket
				#single digit duplicate not allowed. exit
				else:
					print "Case 5a:Single digit duplicate of %r not allowed"%single_digit_list[i]
					print lottery_ticket
					break
			else:
				print "Case 5b:Single digit %r maxed out or out of range"%single_digit_list[i]
				print lottery_ticket
				break
	#out of the while loop, check the size of lottery ticket
	if (len(lottery_ticket)!= 7):
		print "XXXXXXXXXX"
		return []
	else:
		return lottery_ticket


#Loop through the lottery entries to pick the valid ones
for test_str in lottery_list:
	length=len(test_str)
	if (length >=7 and length <=14):
		output = parse_lottery_ticket(test_str,length)
		if (output!=[]):
			print "Entry %r is a valid lottery ticket: %r"%(test_str,output)
			print "------------------------------------------------------------"
