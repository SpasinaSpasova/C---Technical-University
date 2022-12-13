public class Fork {
    public static void fork2(){
        Thread t2=new Thread() {
            public void run() {
                while (true) {
                    fork1();
                }
            }
        };
        t2.start();
    }
    public static void fork1() {
        Thread t1=new Thread() {
            public void run() {
                while (true) {
                    fork2();
                }
            }
        };
        t1.start();
    }
    public static void main(String[] args) {fork1();}
}