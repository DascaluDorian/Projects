import java.util.LinkedList;

public class Consumer implements Runnable{

	LinkedList<Produce> list = new LinkedList<Produce>();
	
	public Consumer(LinkedList<Produce> list) {
		// TODO Auto-generated constructor stub
		this.list = list;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true)
		{
				synchronized (list) {
					while(list.size() == 0){
						try {
							list.wait();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				
				System.out.println("Produce consumed");
				list.notifyAll();
				list.removeLast();
				
				try {
					Thread.sleep(3000);
					} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					}
				}
							
		}
	}

}
