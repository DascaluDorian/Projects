
public class Main {

	static Object cond = new Object();
	public static Semaphore semaphore = new Semaphore(2, cond);

	public Main() {
	}
	public static void main(String[] args) throws InterruptedException {

		Thread prod1 = new Thread(new Usage(semaphore, 1));
		Thread prod2 = new Thread(new Usage(semaphore, 2));
		Thread cons1 = new Thread(new Usage(semaphore, 3));
		Thread cons2 = new Thread(new Usage(semaphore, 4));
		
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