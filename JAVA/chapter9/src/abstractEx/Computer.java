package abstractEx;

public abstract class Computer {
	
	public abstract void display();
	public abstract void typing();
	
	public int add(int x, int y) { return x+y; };
	
	public void turnOn() {
		System.out.println("������ �մϴ�.");
	}
	
	public void turnOff() {
		System.out.println("������ ���ϴ�.");
	}
	
	
}
