# Module 6 Assignment: Moving Between Rooms
# IT-140 Introduction to Scripting
# By: Robert Harmon
# =================================================================================================================

# Define a function for the introduction to the game
def introduction():
    print('Welcome to this text based game.')
    print('Enter commands to perform actions to play the game.')
    commands()
    print('Enter \"begin\" to begin the game')
    print('=' * 75)


# Main function that executes game
def main():
    # Variables to be used in the game
    user_location = 'Stone room'
    user_inventory = 0  # number of items user has found
    directions = ['north', 'south', 'east', 'west']

    # Dictionary for the rooms, description, items, and possible movement directions to be used later
    rooms = {
              'Stone room': {
                             'item': 'none',
                             'east': 'Main Hall',
                             'description': 'the small stone room you woke up in. There is a door to the east.'
                             },
              'Main Hall': {
                            'item': 'parchment',
                            'north': 'Dungeon',
                            'south': 'Cold room',
                            'east': 'Ghost room',
                            'west': 'Stone room',
                            'description': ('a large room that appears to be the center of a castle.\n'
                                            'There are doors to the north, south, east, and west.')
                            },
              'Dungeon': {
                            'item': 'parchment',
                            'south': 'Main Hall',
                            'east': 'Snake room',
                            'west': 'Spider room',
                            'description': ('a small room with chains and bones strewn across the room. \n'
                                            'There are doors to the south, east, and west.')
                            },
              'Spider room': {
                              'item': 'parchment',
                              'east': 'Dungeon',
                              'description': ('which contains numerous spiders and webs. \n'
                                              'There is a door to the east')

                            },
              'Snake room': {
                              'item': 'parchment',
                              'west': 'Dungeon',
                              'description': ('which contains many varieties of snakes around the room. \n'
                                              'There is a door to the west')
                            },
              'Ghost room': {
                              'item': 'parchment',
                              'west': 'Main Hall',
                              'description': ('which contains apparitions slowly drifting around the room. \n'
                                              'There is a door to the west.')
                            },
              'Cold room': {
                              'item': 'parchment',
                              'north': 'Main Hall',
                              'east': 'Monster\'s Lair',
                              'description': ('an empty room that is eerily cold. \n'
                                              'There is a door to the north and east. The east door has ice on it...')
                            },
              'Monster\'s Lair': {
                                  'item': 'none',
                                  'west': 'Cold room',
                                  'description': 'the shadow monster\'s lair. '
                                  }
             }

    # Start the game with the beginning function
    beginning()

    # Print user location
    location(user_location, rooms)
    # will need to also print out item in room

    # Get command as input from user, convert to lower for comparisons
    command = input('Enter a command: ').lower().split()

    # While loop including movement for the game
    # Continues until exit is typed, win or loss conditions to be added later
    while 'exit' not in command:

        # Check that input is 1 or 2 words, if not have user retry command
        if (len(command) < 1) or (len(command) > 2):
            print('Invalid command. Please try again.')

        # Check if command is move with a direction, and check if user meets monster without all items
        elif (command[0] == 'move') and (command[1] in directions):
            if command[1] in rooms[user_location]:
                print('You moved to the', rooms[user_location][command[1]], ':')
                user_location = rooms[user_location][command[1]]
                print(rooms[user_location]['description'])
            else:
                print('You cannot move in this direction.')
            if user_location == 'Monster\'s Lair':
                if user_inventory == 6:
                    print('You see a large, dark, shadowy figure in the room. It turns to look at you.')
                    print('You feel a sudden chill and dread come over you. But somehow you remember the spell.')
                    print('You quickly find how the parchment pieces fit together as the shadow monster gets closer.')
                    print('You read the spell and the monster pauses. Did it work? The monster slowly fades away.')
                    print('Suddenly you wake up in your bed. You think to yourself what a crazy dream that was.')
                    print('You roll over and feel something in your pocket. It\'s a compass and pieces of parchment...')
                    print('You win, thanks for playing!')
                    exit()
                else:
                    print('You see a large, dark, shadowy figure in the room. It turns to look at you.')
                    print('You feel a sudden chill and dread come over you.')
                    print('The shadow monster approaches you, then everything goes black...')
                    print('GAME OVER. Find all the items before finding the monster next time.')
                    exit()

        # If statement for get item command
        elif command[0] == 'get' and command[1] == 'item':
            if rooms[user_location]['item'] != 'none':
                print('You obtained 1 parchment piece.')
                if user_inventory == 0:
                    print('The parchment says \"Use this spell to defeat the...\"')
                    print('That\'s all this piece says. Better look for other pieces')
                user_inventory += 1  # increment inventory item total
                if user_inventory == 6:  # if user found all items
                    print('You found all the parchment pieces for the spell.')
                    print('Assembling the pieces reveals the text \"Use this spell to defeat the shadow monster\"')
                    print()
                rooms[user_location]['item'] = 'none'
            else:
                print('There is no item in this room.')

        # If user inputs status
        elif command[0] == 'status':
            status(user_location, user_inventory, rooms)

        # If user inputs commands for help
        elif command[0] == 'commands':
            commands()

        # Else an invalid command was given
        else:
            print('Invalid command. Please try again.')

        print()

        # Get the next command from user
        command = input('Enter a command: ').lower().split()

    # Exit game if command is exit
    if 'exit' in command:
        print('You have exited the game.')
        exit()


# Function to print beginning of the game
def beginning():
    print('You suddenly wake up in a panic!')
    print('You are in a small room. The walls and floor are all stone.')
    print('The only light is from two torches on the wall.')
    print('You are confused and frightened because you have no idea how you got here.')
    print('The last thing you remember was going to sleep in your bed. Everything feels real though.')
    print('As you stand up you notice something in your pocket and find a compass.')
    print()


# Function to print user location
def location(user_location, rooms):
    print('Your location is:')
    print(user_location, ':', rooms[user_location]['description'])


# Function to print usable commands for user
def commands():
    print('Usable commands: \n\"move north\" \n\"move south\" \n\"move east\" \n\"move west\"')
    print('\"get item\" to pick up the item in the room')
    print('\"status\" to see your location, inventory of items, and what room you are in')
    print('\"commands\" to see available commands for the game')
    print('Enter \"exit\" to end the game')


# Status function to print user location, inventory, items in room
def status(user_location, user_inventory, rooms):
    print('Your location is:', user_location)
    print(rooms[user_location]['description'])
    print('Your inventory:', user_inventory, 'parchment pieces')
    print('Item in this room:', rooms[user_location]['item'])


# End of game functions
# =================================================================================================================

# Call functions to play game
introduction()
intro_commands = ['begin', 'exit']

start = input('Enter \"begin\" to start game, exit to quit: ').lower()

while start not in intro_commands:
    start = input('Enter \"begin\" to start game, \"exit\" to quit: ').lower()

if start == 'exit':
    print('You have exited the game.')
    exit()

if start == 'begin':
    print('=' * 75)
    main()
