import java.util.LinkedList;

public class Main {
	
	static LinkedList<Produce> list = new LinkedList<>();
	public Main() {
		
	}

	public static void main(String[] args) throws InterruptedException {
		Thread prod = new Thread(new Producer(list));
		Thread cons = new Thread(new Consumer(list));
		
		prod.start();
		cons.start();
		
		prod.join();
		cons.join();
	}
	
}

