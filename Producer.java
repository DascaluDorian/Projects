import java.util.LinkedList;

public class Producer implements Runnable{
	public int MAX_NO_OF_PRODUCTS = 5;
	LinkedList<Produce> list = new LinkedList<>();
	
	public Producer(LinkedList<Produce> list) {
		// TODO Auto-generated constructor stub
		this.list = list;
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		while (true)
		{

		if( list.size() == MAX_NO_OF_PRODUCTS){
				/* do nothing */
				System.out.println("List is full");
			}
		else
			{
				Produce produce = new Produce();
				synchronized (list) {
					list.add(produce);
					System.out.println("Produce is produced");
				}
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
