import java.util.LinkedList;

public class Consumer implements Runnable{

	LinkedList<Produce> list = new LinkedList<Produce>();
	SemaphoreList semaphores;
	
	public Consumer(LinkedList<Produce> list, SemaphoreList semaphores) {
		// TODO Auto-generated constructor stub
		this.list = list;
		this.semaphores = semaphores;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true)
		{
			try {
				semaphores.semFull.acquire();
				synchronized (list) {
					list.removeLast();
				}
				System.out.println("Produce consumed");
				semaphores.semFree.release();
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
							
		}
	}

}
