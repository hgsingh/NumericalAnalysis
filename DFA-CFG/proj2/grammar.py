import json #import json library to read

#loading file information here
#load json structures this is similar to project 1
file_name = "grammar1.json"
cfg = json.load(open(file_name))
nonterminals = cfg["nonterminals"]
terminals = cfg["terminals"]
start = cfg["start"]
transition_object = cfg["delta"]
input_strings = cfg["strings"]


#this function will look at a string and determine
#if all the characters in the string belong to the set of terminals
#if they do it will continue with the derivation
def buffer_test(input_string):
    for character in string:
        if character  not in terminals:
            print("Not a valid string")
            return 0
    return 1

#this function describes the derivation of the string
#it passes the string as an argument and then creates a stack structure
#the stack structure is used for the nonterminals and terminals to check against the input string
#the function checks the stack for nonterminals and terminals to take appropriate action
def derivation(input_string):
    derivation_stack = []
    derivation_stack.append(start) #append the start symbol
    seq  = len(input_string) #derivation sequence complete
    if(seq == 0):#no input given
        return 0
    while seq >  0:
        char =  input_string[0] #take the first character in input
        stack_top = len(derivation_stack) - 1 #ranges from -1 to len(x) -1
        if(stack_top == -1): #no input given
            return 0
        element = derivation_stack.pop() #get the next rule or terminal from the stack
        if element in nonterminals: #popped element is part of the nonterminals
            check  = get_rule(char, element, derivation_stack, stack_top) #check the rule and update stack
            if check == 0: #no rule found return here 
                return 0
        if element in terminals: #the element is a terminal then update string and check for the match
            if char  == element:
                seq = len(input_string[1:])
                input_string = input_string[1:] 
            else:
                return 0
    if not derivation_stack and not input_string:
        return 1
    return 0

#this updates the stack if the rule is found in the json object
#it reverses the string and then appends to the stack
#further it compares the previous and new positions of the stack
#this is done to see if the stack was updated, if not no rule is found and 0 is returned
def get_rule(buffer_element, rule, stack, stack_top):
    new_stack_top = stack_top
    for tr in transition_object[rule]:#go to the rule
        if buffer_element == tr[0]: #check the first char of the rule
            for char in tr[::-1]: #reverse string and append
                stack.append(char)
                new_stack_top = stack_top + 1
    if(new_stack_top == stack_top): #no rule found
        return 0
    return 1

#main entry point 
#tests all the strings in the input_strings array and uses them to find derivations for the string
if __name__ == "__main__":
    for string in input_strings:
        print("inputing :" +  string )
        if buffer_test(string) != 0:
            if derivation(string) == 1:
                print "success"
            else:
                print "fail"
