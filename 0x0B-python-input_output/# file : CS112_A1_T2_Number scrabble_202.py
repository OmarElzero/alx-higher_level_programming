# file : CS112_A1_T2_Number scrabble_20231058.py.
#Purpose : we have 9 numbers then  the player choose 3 numbers their summation is 15 to win
#Author : Radwa Essam Mohamed El Sayed Mohamed
#ID : 20231058
Number_list = [1,2,3,4,5,6,7,8,9]
print(" ")
print("** Hello in the game **")
print(" ")
print("You should choose set of numbers three of them their summation should equal 15")
player_one_list = []
player_two_list = []
print(" ")
print(Number_list)
print(" ")
while True :
#the player's one turn
   while True :
    try:   
     choice1 = int(input("player one , please enter a number: "))

#make sure the player enter a valid number
     if choice1 in Number_list :
         break
     else :
         print("please enter a valid number")
#add the number to the player_one_list
     player_one_list.append(choice1)

#remove the selected number from Number_list
     for item in Number_list :
      if item == choice1 :
       Number_list.remove(item)
#verify that the sum of the three numbers is 15
      if len(player_one_list)>=3 :
       for n in range(len(player_one_list)) :
        for o in range(n+1 ,len(player_one_list)) :
          for p in range(o+1 ,len(player_one_list)) :
             if player_one_list[n] + player_one_list[o] + player_one_list[p] == 15 :
                print("player one is a winner")
                raise SystemExit
             else :
                    continue
    except ValueError:
       print("invalid input , only numbers allowed")
#in case of a draw
   while True:
       
      if Number_list == [ ]:
           print("it is a draw")
           raise SystemExit
      else:
           break
   print(Number_list)
#the player's two turn
   while True :
    try:   
     choice2 = int(input("player two please enter a number : "))
# make sure the player enter a valid number
     if choice2 in Number_list :
        break
     else :
        print("please enter a valid number")
#add the number to the player_two_list
     player_two_list.append(choice2)
#remove the selected number from Number_list
     for item in Number_list:
      if item == choice2:
         Number_list.remove(item)
# verify that the sum of the three numbers is 15
     if len(player_two_list) >= 3:
      for n in range(len(player_two_list)):
        for o in range(n + 1, len(player_two_list)):
          for p in range(o + 1, len(player_two_list)):
            if player_two_list[n] + player_two_list[o] + player_two_list[p] == 15:
                 print("player two is a winner")
                 raise SystemExit
            else :
                 continue
     print(Number_list)               
    except ValueError:
        print("invalid input , only numbers allowed")
    