import sys
import os
JMBG = raw_input('Please enter your JMBG:')

if len(JMBG)!= 13 :
        print 'Invalid JMBG!'
        sys.exit()
elif not JMBG.isdigit():
        print 'There were letters in JMBG!\nInvalid JMBG!'
        sys.exit()
else:
        if JMBG[2:4] == '01':
                if JMBG[0:1]>'31':
                        print 'January has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '02':
                if JMBG[5] == '9':
                        if int(JMBG[4:7])%4 ==0:
                                if JMBG[0:2]>'29':
                                        print 'February has only 29 days!\n Invalid JMBG'
                                        sys.exit()
                        else:
                                if JMBG[0:2]>'28':
                                        print 'February has only 28 days!\n Invalid JMBG'
                                        sys.exit()
                elif JMBG[5] == '0':
                        god = 2000+ int(JMBG[4:7])
                        if god % 4 == 0:
                                if JMBG[0:2]>'29':
                                        print 'February has only 29 days!\n Invalid JMBG'
                                        sys.exit()
                        else:
                                if JMBG[0:2]>'28':
                                        print 'February has only 28 days!\n Invalid JMBG'
                                        sys.exit()
                else:
                        print 'Invalid year of birth\nInvalid JMBG'
        elif JMBG[2:4] == '03':
                if JMBG[0:2]>'31':
                        print 'March has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '04':
                if JMBG[0:2]>'30':
                        print 'April has only 30 days!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '05':
                if JMBG[0:2]>'31':
                        print 'May has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '06':
                if JMBG[0:2]>'30':
                        print 'June has only 30 days!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '07':
                if JMBG[0:2]>'31':
                        print 'July has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '08':
                if JMBG[0:2]>'31':
                        print 'August has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '09':
                if JMBG[0:2]>'30':
                        print 'September has only 30 days!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '10':
                if JMBG[0:2]>'31':
                        print 'October has only 31 day!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '11':
                if JMBG[0:2]>'30':
                        print 'November has only 30 days!\n Invalid JMBG'
                        sys.exit()
        elif JMBG[2:4] == '12':
                if JMBG[0:2]>'30':
                        print 'December has only 31 day!\n Invalid JMBG'
                        sys.exit()
        else:
                print 'Invalid Month of birth!\nInvalid JMBG!'
                sys.exit()
if JMBG[7:9] != '03' and (int(JMBG[7:9])<30 or int(JMBG[7:9])>39):
        print 'Invalid region of residence!\nInvalid JMBG'
        sys.exit()
if int(JMBG[9:12])<500:
        print 'male'
elif int(JMBG[9:12]>499):
        print 'female'
cont = int(JMBG[0])*7+int(JMBG[1])*6+int(JMBG[2])*5+int(JMBG[3])*4+int(JMBG[4])*3+int(JMBG[5])*2+int(JMBG[6])*7+int(JMBG[7])*6+int(JMBG[8])*5+int(JMBG[9])*4+int(JMBG[10])*3+int(JMBG[11])*2
ost = cont % 11
K = 11 - ost
if int(JMBG[12])!= K:
        print 'Control number is invalid!\nInvalid JMBG'
        sys.exit()
else:
        print 'Your JMBG is valid. :D\n' +JMBG 

