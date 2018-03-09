import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class Main {
	
	static int n = 2;
	static LinkedList<Produce> list = new LinkedList<>();
	public static SemaphoreList semaphores;
	
	public Main() {
		//semaphores = new SemaphoreList(n);
	}

	public static void main(String[] args) throws InterruptedException {
		semaphores = new SemaphoreList(n);
		Thread prod1 = new Thread(new Producer(list, semaphores));
		Thread prod2 = new Thread(new Producer(list, semaphores));
		Thread cons1 = new Thread(new Consumer(list, semaphores));
		Thread cons2 = new Thread(new Consumer(list, semaphores));
		
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

