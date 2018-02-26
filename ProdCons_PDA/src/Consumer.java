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
			if(list.size() == 0){
				/* do nothing */
				System.out.println("List is empty");
			}
			else{
				synchronized (list) {
					list.removeLast();
					System.out.println("Produce consumed");
				}
				try {
					Thread.sleep(5000);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
		}
	}

}
