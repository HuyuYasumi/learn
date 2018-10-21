
public class MobilePhone {
	private String brand;
	private	double price;
	private int serial;
	
	public MobilePhone() {
		price = 1000;
	}
	
	public MobilePhone(String brand, double price) {
		this.brand = brand;
		this.price = price;
	}

	public void setPrice(double price) {
		this.price = price;
	}
	
	public void setBrand(String brand) {
		this.brand = brand;
	}
	
	public double getPrice() {
		return price;
	}
	
	public String getBrand() {
		return brand;
	}
	
	public static void main(String[] args) {
		MobilePhone[] myPhone = new MobilePhone[2];
		myPhone[0] = new MobilePhone();
		myPhone[1] = new MobilePhone("Sony", 4000);
		myPhone[0].setBrand("Google");
		for(MobilePhone e : myPhone) {
			System.out.println(e.getBrand() + ":\t" + e.getPrice());
		}
	}
}
