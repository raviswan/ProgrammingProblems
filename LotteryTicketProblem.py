lottery_list=[ "1", "42", "100848", "4938532894754", "1234567", "472844278465445"]
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

def is_duplicate_present(arg):
	"""
	Returns True if a duplicate is present in "arg" list. Else return false
	"""
	arg_cpy=list(arg)
	for x in arg_cpy:
		arg_cpy.remove(x)
		if(x in arg_cpy):
			return True;
		arg_cpy=list(arg)
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
	index = 0
	while(index<length):
		#add 2 digit entry to lottery list if in valid range
		if(double_digit_count>0):
			#can we add the next 2 digits to the lottery
			if int(double_digit_list[index]) in valid_range:
				lottery_ticket += [double_digit_list[index]]
				#if unique element,decrement allowable 2-digits and up index by 2
				if(is_duplicate_present(lottery_ticket)==False):
					double_digit_count -= 1
					index += 2
				#if duplicate, split double digits into single
				else:
					#duplicate entry can't be added,remove it
					lottery_ticket = [lottery_ticket[i] for i in range(0,len(lottery_ticket)-1)]
					#Try single digit entry now
					if ((single_digit_count>0) and (int(single_digit_list[index]) in valid_range)):
						lottery_ticket += [single_digit_list[index]]
						if(is_duplicate_present(lottery_ticket)==False):
							single_digit_count -= 1
							index += 1
						#single digit duplicate not allowed. exit
						else:
							lottery_ticket = [lottery_ticket[i] for i in range(0,len(lottery_ticket)-1)]
							break
					else:
						break
			#when double digit is not valid, try splitting it
			elif ((single_digit_count>0)and (int(single_digit_list[index]) in valid_range)):
					lottery_ticket += [single_digit_list[index]]
					if(is_duplicate_present(lottery_ticket)==False):
						single_digit_count -= 1
						index += 1
					#single digit duplicate not allowed. exit
					else:
						lottery_ticket = [lottery_ticket[i] for i in range(0,len(lottery_ticket)-1)]
						break
			else:
				break
		#for single-digit-only cases or when out of max double digits allowed
		else:
			if((single_digit_count>0) and (int(single_digit_list[index]) in valid_range)):
				lottery_ticket += [single_digit_list[index]]
				if(is_duplicate_present(lottery_ticket)==False):
					single_digit_count -= 1
					index += 1
				#single digit duplicate not allowed. exit
				else:
					lottery_ticket = [lottery_ticket[i] for i in range(0,len(lottery_ticket)-1)]
					break
			else:
				break
	#out of the while loop, check the size of lottery ticket
	if (len(lottery_ticket)!= 7):
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
