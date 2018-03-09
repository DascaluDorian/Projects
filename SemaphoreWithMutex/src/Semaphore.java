import java.util.LinkedList;

public class Semaphore {

	public int maxDimension;
	LinkedList<Integer> usage = new LinkedList<>();
	
	public Semaphore(int dimension) {
		this.maxDimension = dimension;
	}

	public void acquire()
	{
		boolean semaphoreNotAquired = true;
		
		while (semaphoreNotAquired){		
			
			synchronized (usage) {
				if(usage.size() < maxDimension)
				{
					usage.add(1);
					semaphoreNotAquired = false;
					System.out.println(">>> Semaphore aquired");
				}
			}
		}
	}

	public void release(){
		synchronized (usage) {
			usage.removeFirst();
			System.out.println("Semaphore released");
		}
	}
}
