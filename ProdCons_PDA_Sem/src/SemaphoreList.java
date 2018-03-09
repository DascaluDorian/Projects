import java.util.concurrent.Semaphore;

public class SemaphoreList {

	int n;
	public Semaphore semFree;
	public Semaphore semFull;
	
	public SemaphoreList(int number) {
		n = number;
		semFree = new Semaphore(n);
		semFull = new Semaphore(0);
	}
	
	

}
