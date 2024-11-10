package lab4_2;

public class Human {

	private String fullName;
	private String citizenID;
	private String sex;
	private String Nationality;

	public Human() {
	};

	public Human(String fullName, String citizenID, String sex, String nationality) {
		this.fullName = fullName;
		this.citizenID = citizenID;
		this.sex = sex;
		Nationality = nationality;
	}

	public String getFullName() {
		return fullName;
	}

	public void setFullName(String fullName) {
		this.fullName = fullName;
	}

	public String getCitizenID() {
		return citizenID;
	}

	public void setCitizenID(String citizenID) {
		this.citizenID = citizenID;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public String getNationality() {
		return Nationality;
	}

	public void setNationality(String nationality) {
		Nationality = nationality;
	}

	public static boolean invalidCitizenID(String citizenID) {
		boolean checkNumberic = citizenID.matches("\\d+");
		if (citizenID.length() != 7 || !checkNumberic) {
			System.out.println("Invalid CitizenID");
			return false;
		}
		return true;
	}

	public static boolean invalidSex(String sex) {
		if (sex.equals("Male") || sex.equals("Female"))
			return true;
		System.out.println("Invalid Sex");
		return false;
	}

}
