
public class DayOfYear {
	private int month;
	public DayOfYear(int month) {
		if(month >= 1 && month <= 12) {
			this.month = month;
		} else {
			System.out.println("请输入正确月份");
		}
	}
	public int getDays(int day) {
		switch(month) {
			case 1:
				return day;
			case 2:
				return 31+day;
			case 3:
			case 5:
			case 7:
				return 31+28+(month-3)/2*(31+30)+day;
			case 4:
			case 6:
				return 31+28+31+(month-4)/2*(30+31)+day;
			case 8:
			case 10:
			case 12:
				return 31+28+31+30+31+30+31+(month-8)/2*(31+30)+day;
			case 9:
			case 11:
				return 31+28+31+30+31+30+31+31+(month-9)/2*(30+31)+day;
			default:
				return 0;
		}
	}

	public static void main(String[] args) {
		DayOfYear date = new DayOfYear(3);
		DayOfYear date2 = new DayOfYear(8);
		System.out.println(date.getDays(15));
		System.out.println(date2.getDays(15));
	}

}
