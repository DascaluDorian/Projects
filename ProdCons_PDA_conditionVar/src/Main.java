import java.util.LinkedList;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		LinkedList<Produce> list = new LinkedList<>();
		
		Thread prod1 = new Thread(new Producer(list));
		Thread prod2 = new Thread(new Producer(list));
		Thread cons1 = new Thread(new Consumer(list));
		Thread cons2 = new Thread(new Consumer(list));
		
		prod1.start();
		prod2.start();
		cons1.start();
		cons2.start();
		
		prod1.join();
		prod2.join();
		cons1.join();
		cons2.join();

	}
}

