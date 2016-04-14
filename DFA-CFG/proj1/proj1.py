import json #json library used for reading json file  

file_name = "evenzeros.json" #filename string used to open the file
dfa = json.load(open(file_name)) #json library used to read the json file
states = dfa["states"] #states list read in from the json file
alphabet = dfa["alphabet"] #alphabet list read in from the json file
start_state = dfa["start"] #start state
transition_table = dfa["delta"] #transition table defined by the json object
accepted_states = dfa["accept_states"] #accepted states list
input_strings = dfa["strings"] #input string list
#string = raw_input("please input a string for the DFA \n")

#dfa test function
#arguments: input string string to be tested in the DFA
#function: compares the characters in the string to the list of the alphabet found 
#returns 1 if all the characters in the string match the alphabet, 0 if they don't 
def dfa_test(input_string):
    for character in string:
        if character  not in alphabet:
            print("Not a valid string")
            return 0
        return 1

#dfa transition function
#arguments:input string to parse to the dfa
#function: parses the string through the dfa and if the state is accepted then returns a 1 or 0 if it failed
def transit(input_string):
    #print("valid string identified")
    state = start_state
    for character in string:
        state = transition_table[state][character]
    for a_state in accepted_states:
        if state == a_state:
            print("accepted")
            return 1
    return 0

#main entry point 
#tests all the strings in the input_strings array and parses them through the dfa
if __name__ == "__main__":
    for string in input_strings:
        print("inputing :" +  string )
        if dfa_test(string) != 0:
            transit(string)

