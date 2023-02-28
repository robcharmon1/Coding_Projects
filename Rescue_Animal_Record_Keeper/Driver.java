// Driver file for Grazioso Salvare Animal Rescue
// Robert Harmon

import java.util.ArrayList;
import java.util.Scanner;

public class Driver {
	
	// Private fields
    private static ArrayList<Dog> dogList = new ArrayList<Dog>();
    private static ArrayList<Monkey> monkeyList = new ArrayList<Monkey>();
    private static String[] monkeySpecies = {"Capuchin", "Guenon", "Macaque", "Marmoset", "Squirrel monkey", "Tamarin"};
    
    // Main Function
    public static void main(String[] args) {

        initializeDogList();
        initializeMonkeyList();

        // Initialize variables for user input and scanner for input
        char userInput = '0';
        Scanner scnr = new Scanner(System.in);
                      
        // Loop to display menu, take user input, and take appropriate action until user quits 
        while (userInput != 'q') {
        	
        	// Display the menu options
        	displayMenu();
        	
        	// Get user input as first char of input string
        	userInput = scnr.nextLine().charAt(0);
        	
        	// Perform appropriate actions for user input based on menu
        	if (userInput == '1') {
        		intakeNewDog(scnr);
        	}
        	else if (userInput == '2') {
        		intakeNewMonkey(scnr);
        	}
        	else if (userInput == '3') {
        		reserveAnimal(scnr);
        	}
        	else if (userInput == '4') {
        		printAnimals(userInput);
        	}
        	else if (userInput == '5') {
        		printAnimals(userInput);
        	}
        	else if (userInput == '6') {
        		printAnimals(userInput);
        	}
        	else if (userInput == 'q') {
        		System.out.println("Exiting program.");
        	}
        	else {  // input is invalid
        		System.out.println("Please enter a valid input from the menu.");
        	}       	
        }
    }
    
    
    // =====================================================================================
    // This method prints the menu options
    public static void displayMenu() {
        System.out.println("\n\n");
        System.out.println("\t\t\t\tRescue Animal System Menu");
        System.out.println("[1] Intake a new dog");
        System.out.println("[2] Intake a new monkey");
        System.out.println("[3] Reserve an animal");
        System.out.println("[4] Print a list of all dogs");
        System.out.println("[5] Print a list of all monkeys");
        System.out.println("[6] Print a list of all animals that are not reserved");
        System.out.println("[q] Quit application");
        System.out.println();
        System.out.println("Enter a menu selection");
    }

    // =====================================================================================
    // Adds dogs to a list for testing
    public static void initializeDogList() {
        Dog dog1 = new Dog("Spot", "German Shepherd", "male", "1", "25.6", "05-12-2019", "United States", "intake", false, "United States");
        Dog dog2 = new Dog("Rex", "Great Dane", "male", "3", "35.2", "02-03-2020", "United States", "Phase I", false, "United States");
        Dog dog3 = new Dog("Bella", "Chihuahua", "female", "4", "25.6", "12-12-2019", "Canada", "in service", false, "Canada");

        dogList.add(dog1);
        dogList.add(dog2);
        dogList.add(dog3);
    }

    // =====================================================================================
    // Adds monkeys to a list for testing
    public static void initializeMonkeyList() {
    	Monkey monkey1 = new Monkey("Coco", "male", "10", "50", "1-1-2015", "Madagascar", "in service", false, 
    			"United States", "2.1", "3.5", "5", "Macaque");
    	
    	monkeyList.add(monkey1);
    }

    // =====================================================================================
    // Method to enter info for a new Dog
    public static void intakeNewDog(Scanner scanner) {
        System.out.println("What is the dog's name?");
        String name = scanner.nextLine();
        for(Dog dog: dogList) {
            if(dog.getName().equalsIgnoreCase(name)) {
                System.out.println("\n\nThis dog is already in our system\n\n");
                return; //returns to menu
            }
        }

        // Get user inputs for new Dog info
        System.out.println("What is the dog's breed?");
        String breed = scanner.nextLine();
        
        System.out.println("What is the dog's gender?");
        String gender = scanner.nextLine();
        
        System.out.println("What is the dog's age?");
        String age = scanner.nextLine();
        
        System.out.println("What is the dog's weight?");
        String weight = scanner.nextLine();
        
        System.out.println("What is the dog's aquisition date?");
        String aquisitionDate = scanner.nextLine();
        
        System.out.println("What is the dog's aquisition country?");
        String aquisitionCountry = scanner.nextLine();
        
        System.out.println("What is the dog's training status?");
        String trainingStatus = scanner.nextLine();
        
        System.out.println("Is the dog reserved?");
        boolean reserved = scanner.nextBoolean();
        
        System.out.println("What is the dog's service country?");
        String inServiceCountry = scanner.nextLine();
        
        // Create new object for new input dog
        Dog newDog = new Dog(name, breed, gender, age, weight, aquisitionDate, aquisitionCountry, 
        		trainingStatus, reserved, inServiceCountry);
        
        // Add dog to do array list
        dogList.add(newDog);   
    }

    // =====================================================================================
        // Method to enter info for new Monkey
        public static void intakeNewMonkey(Scanner scanner) {
        	System.out.println("What is the monkey's name?");
            String name = scanner.nextLine();
            
            for(Monkey monkey: monkeyList) {
                if(monkey.getName().equalsIgnoreCase(name)) {
                    System.out.println("\n\nThis ,monkey is already in our system\n\n");
                    return; //returns to menu
                }
            }
            
            // Get user inputs for new monkey info
            System.out.print("What is the monkey's gender");
            String gender = scanner.nextLine();
            
            System.out.print("What is the monkey's age");
            String age = scanner.nextLine();
            
            System.out.print("What is the monkey's weight");
            String weight = scanner.nextLine();
            
            System.out.print("What is the monkey's acquisition date");
            String acquisitionDate = scanner.nextLine();
            
            System.out.print("What is the monkey's acquisition Country");
            String acquisitionCountry = scanner.nextLine();
            
            System.out.print("What is the monkey's trainig status");
            String trainigStatus = scanner.nextLine();
            
            System.out.print("Is the monkey reserved? (true or false");
            boolean reserved = scanner.nextBoolean();
            
            System.out.print("What is the monkey's in service country");
            String inServiceCountry = scanner.nextLine();
            
            System.out.print("What is the monkey's tail length");
            String tailLength = scanner.nextLine();
            
            System.out.print("What is the monkey's height");
            String height = scanner.nextLine();
            
            System.out.print("What is the monkey's body length");
            String bodyLength = scanner.nextLine();
            
            System.out.print("What is the monkey's species");
            String species = scanner.nextLine();
            
            // Validate monkey species is an accepted species
            boolean validSpecies = false;
            for (String type : monkeySpecies) {
            	if (species.equalsIgnoreCase(type)) {
            		validSpecies = true;
            	}
            }
            if (validSpecies == false) {
            	System.out.println("Not an accepted monkey species.");
            	System.out.println("Accepted species: Capuchin, Guenon, Macaque, Marmoset, Squirrel monkey, Tamarin");
            	return; // return to menu
            }
            
            // Create new object for new input monkey
            Monkey newMonkey = new Monkey(name, gender, age, weight, acquisitionDate, acquisitionCountry, trainigStatus,
            		reserved, inServiceCountry, tailLength, height, bodyLength, species);
            
            // Add new monkey to monkey array list
            monkeyList.add(newMonkey);                       
        }
        
        // ===========================================================================================
        // Method to check if a desired animal type in a desired country is available to reserve for service
        public static void reserveAnimal(Scanner scanner) {
        	
        	int reserveSuccess = 0;  // variable to keep track of whether an animal has been successfully reserved
        	
        	// Get input for animal type
        	System.out.println("What type of animal are you looking for?");
            String animalType = scanner.nextLine();
            
            // Get input for service country
            System.out.println("What country do you need service in?");
            String serviceCountry = scanner.nextLine();
            
            // Check if there is an available animal
            if (animalType.equalsIgnoreCase("dog")) {
            	for(Dog dog: dogList) {
            		if (dog.getInServiceLocation().equalsIgnoreCase(serviceCountry)) {
            			if ((dog.getReserved() == false) && (dog.getTrainingStatus() == "in service")) {
            				System.out.println("Dog " + dog.getName() + " is available and will be reserved.");
            				dog.setReserved(true);
            				reserveSuccess = 1;
            				return;
            			}
            		}
            	}
            	if (reserveSuccess == 0) {
            		System.out.print("There are no dogs available in " + serviceCountry);
            	}
            }
            else if (animalType.equalsIgnoreCase("monkey")) {
            	for (Monkey monkey : monkeyList) {
            		if (monkey.getInServiceLocation().equalsIgnoreCase(serviceCountry)) {
            			if ((monkey.getReserved() == false) && (monkey.getTrainingStatus() == "in service")) {
            				System.out.println("Monkey " + monkey.getName() + " is available and will be reserved.");
            				monkey.setReserved(true);
            				reserveSuccess = 1;
            				return;
            			}
            		}
            	}
            	if (reserveSuccess == 0) {
            		System.out.print("There are no monkeys available in " + serviceCountry);
            	}
            }
            else {
            	System.out.println("Please enter a valid animal type.");
            }
                        

        }

        // ================================================================================================
        // Method to either print all dogs, all monkeys, or all available animals
        public static void printAnimals(char inputChar) { 
            if (inputChar == '4') { // all dogs
            	System.out.println("List of all dogs:");
            	for(Dog dog : dogList) {
            		System.out.println("Name: " + dog.getName() + ", Status: " + dog.getTrainingStatus() + 
            				", Aquisition Country: " + dog.getAcquisitionLocation() + ", Reserved: " + dog.getReserved());
            	}	
            }
            else if (inputChar == '5') { // all monkeys
            	System.out.println("List of all monkeys:");
            	for(Monkey monkey : monkeyList) {
            		System.out.println("Name: " + monkey.getName() + ", Status: " + monkey.getTrainingStatus() + 
            				", Aquisition Country: " + monkey.getAcquisitionLocation() + ", Reserved: " +
            				monkey.getReserved());
            	}
            }
            else { // all available
            	System.out.println("List of all available animals:");
            	for(Dog dog : dogList) {
            		if ((dog.getTrainingStatus() == "in service") && (dog.getReserved() == false)) {
            			System.out.println("Dog name: " + dog.getName() + ", Status: " + dog.getTrainingStatus() + 
                				", Aquisition Country: " + dog.getAcquisitionLocation() + ", Reserved: " +
            					dog.getReserved());
            		}
            	}
            	for(Monkey monkey : monkeyList) {
            		if ((monkey.getTrainingStatus() == "in service") && (monkey.getReserved() == false)) {
            			System.out.println("Monkey name: " + monkey.getName() + ", Status: " + monkey.getTrainingStatus() + 
                				", Aquisition Country: " + monkey.getAcquisitionLocation() + ", Reserved: " +
                				monkey.getReserved());
            		}
            	}
            }
        }
}

