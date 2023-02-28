// Derived Class for Monkey
// Robert Harmon

public class Monkey extends RescueAnimal {
	
	// Instance Variables
	private String tailLength;    // monkey's tail length
	private String height;        // monkey's height
	private String bodyLength;    // monkey's body length
	private String species;       // monkey's species
	
	// Constructor for Monkey Class, uses methods from RescueAnimal Class
    public Monkey(String name, String gender, String age,
    String weight, String acquisitionDate, String acquisitionCountry,
	String trainingStatus, boolean reserved, String inServiceCountry, String tailLength,
	String height, String bodyLength, String species) {
        setName(name);
        setGender(gender);
        setAge(age);
        setWeight(weight);
        setAcquisitionDate(acquisitionDate);
        setAcquisitionLocation(acquisitionCountry);
        setTrainingStatus(trainingStatus);
        setReserved(reserved);
        setInServiceCountry(inServiceCountry);
        setTailLength(tailLength);
        setHeight(height);
        setBodyLength(bodyLength);
        setSpecies(species);
    }
    
    // Mutator method for tail length
    public void setTailLength(String lengthVal) {
    	tailLength = lengthVal;
    }
    
    // Accessor method for tail length
    public String getTailLength() {
    	return tailLength;
    }
    
    // Mutator method for height
    public void setHeight(String heightVal) {
    height = heightVal;
    }
    
    // Accessor method for height
    public String getHeight() {
    	return height;
    }
    
    // Mutator method for body length
    public void setBodyLength(String bodyLengthVal) {
    	bodyLength = bodyLengthVal;
    }
    
    // Accessor method for body length
    public String getBodyLength() {
    	return bodyLength;
    }
    
    // Mutator method for species
    public void setSpecies(String speciesVal) {
    	species = speciesVal;
    	
    }
    
    // Accessor method for species
    public String getSpecies() {
    	return species;
    }

}
