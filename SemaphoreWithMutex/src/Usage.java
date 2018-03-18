
public class Usage implements Runnable{

	public int id;
	public Semaphore semaphore;
	public Usage(Semaphore semaphore, int id) {
		this.semaphore = semaphore;
		this.id = id;
	}
	
	public void run()
	{
		while(true){
			
			try {
				semaphore.acquire();
			} catch (InterruptedException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

			try {
				Thread.sleep((long)(Math.random() * 7000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			
			semaphore.release();

			try {
				Thread.sleep((long)(Math.random() * 7000));
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

}
