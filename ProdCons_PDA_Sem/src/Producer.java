import java.util.LinkedList;

public class Producer implements Runnable{
	LinkedList<Produce> list = new LinkedList<>();
	SemaphoreList semaphores;
	
	public Producer(LinkedList<Produce> list, SemaphoreList semaphores) {
		// TODO Auto-generated constructor stub
		this.list = list;
		this.semaphores = semaphores;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true)
		{	
				Produce produce = new Produce();				
				try {
					semaphores.semFree.acquire();
					synchronized (list) {
						list.add(produce);
					}					
					System.out.println("Produce is produced");
					semaphores.semFull.release();
					Thread.sleep(1000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}				
				
		}
	}
}
