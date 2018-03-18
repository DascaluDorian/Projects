import java.util.LinkedList;

public class Semaphore {

	public int maxDimension;
	LinkedList<Integer> usage = new LinkedList<>();
	Object cond;
	
	public Semaphore(int dimension, Object cond) {
		this.maxDimension = dimension;
		this.cond = cond;
	}

	public void acquire() throws InterruptedException
	{
			synchronized (this) {
				while(usage.size() == maxDimension)
				{
					wait();
				}
				usage.add(1);
			}
			System.out.println(">>> Semaphore aquired, current size : " + usage.size());
	}

	public void release(){
		synchronized (this) {
			usage.remove();
			System.out.println("Semaphore released");
			notifyAll();
		}
	}
}
