import java.util.LinkedList;

public class Producer implements Runnable{
	LinkedList<Produce> list = new LinkedList<>();
	int maxDim = 2;
	
	public Producer(LinkedList<Produce> list) {
		// TODO Auto-generated constructor stub
		this.list = list;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true)
		{	
				Produce produce = new Produce();				
				synchronized (list) {
					while(list.size() == maxDim){
						try {
							list.wait();
						} catch (InterruptedException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}						
				
					list.add(produce);
					System.out.println("Produce is produced");
					list.notifyAll();
					
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
				
		}
	}
}
