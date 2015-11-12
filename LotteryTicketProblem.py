from sys import argv
script, lottery_list = argv

valid_range = str(range(1,60))
print valid_range

#print range_check
#test_str = "4938532894754"
#test_str = "493349125755"
#test_str = "4933187657"
test_str = "4933187652"
test_str = "49331876521"


digit_count_map={7:(7,0), 
				8:(6,1),
				9:(5,2),
				10:(4,3), 
				11:(3,4),
				12:(2,5),
				13:(1,6),
				14:(0,7)
				}

#print [test_str[i:i+n] for i in range(0,len(test_str),n)]

def is_duplicate_present(arg):
	arg_cpy=list(arg)
	for x in arg_cpy:
		arg_cpy.remove(x)
		if(x in arg_cpy):
			return True;
		arg_cpy=list(arg)
	return False


def is_valid_lottery_ticket(str,length):
	lottery_ticket=[]
	single_digit_list=[str[i] for i in range(0,len(str))]
	print "single_digit_list = %r" %(single_digit_list)
	double_digit_list=[str[i:i+2] for i in range(0,len(str))]
	print "double_digit_list = %r" %(double_digit_list)

	dim = digit_count_map[length]
	single_digit_count = dim[0]
	double_digit_count = dim[1]
	print "single digit count=%r, double digit count=%r"%(dim[0],dim[1])
	index = 0
	while(index<length):
		#add 2 digit entry to lottery list if in valid range
		if(double_digit_count>0):
			print double_digit_list[index]
			#can we add the next 2 digits to the lottery
			if double_digit_list[index] in valid_range:
				lottery_ticket += [double_digit_list[index]]
				#if unique element,decrement allowable 2-digits and up index by 2
				if(is_duplicate_present(lottery_ticket)==False):
					double_digit_count -= 1
					index += 2
					print "Lottery ticket1=%r"%(lottery_ticket)
				#if duplicate, lottery number as invalid
				else:
					print "duplicate entry %r can't be added,remove double,try single"%(double_digit_list[index])
					lottery_ticket = [lottery_ticket[i] for i in range(0,len(lottery_ticket)-1)]
					#Try single digit entry now
					if(single_digit_count>0):
						lottery_ticket += [single_digit_list[index]]
						if(is_duplicate_present(lottery_ticket)==False):
							single_digit_count -= 1
							index += 1
							print "Lottery ticket_1=%r"%(lottery_ticket)
						else:
							print " single digit duplicate entry %r not allowed" %(single_digit_list[index])
							return False
			#when double digit can't be added, try single digit as a lottery entry
			elif(single_digit_count>0):
					lottery_ticket += [single_digit_list[index]]
					if(is_duplicate_present(lottery_ticket)==False):
						single_digit_count -= 1
						index += 1
						print "Lottery ticket_2=%r"%(lottery_ticket)
					else:
						print "duplicate entry %r can't be added to lottery list" %(single_digit_list[index])
						#lottery_ticket.remove(single_digit_list[index])
						return False
			else:
				break;

		#for single-digit-only cases or when out of max double digits allowed
		else:
			if(single_digit_count>0):
				lottery_ticket += [single_digit_list[index]]
				if(is_duplicate_present(lottery_ticket)==False):
					single_digit_count -= 1
					index += 1
					print "Lottery ticket_3=%r"%(lottery_ticket)
				else:
					print "duplicate entry %r being added to lottery list" %(single_digit_list[index])
					return False
			else:
				break;
	#out of the loop, check size of lottery ticket
	if (len(lottery_ticket)!= 7):
		print "invalid lottery ticket %r"%(lottery_ticket)
		return False
	else:
		print "valid lottery ticket %r"%(lottery_ticket)
		return True




length=len(test_str)


if (length < 7):
	print "too short"
elif(length==7):
	number_to_test = [test_str[i] for i in range(0,len(test_str))]
	if(is_duplicate_present(number_to_test)):
		print "invalid"
	else:
		print "valid"
elif(length==14):
	number_to_test= [test_str[i:i+2] for i in range(0,len(test_str),2)]
	if(is_duplicate_present(number_to_test)):
		print "invalid"
	else:
		if(is_valid_lottery_ticket(number_to_test)):
			print "valid lottery ticket: %r" %(lottery_ticket) 
elif(length>7 and length<14):
	if(is_valid_lottery_ticket(test_str,length)):
		print "valid"
	else:
		print "invalid"

