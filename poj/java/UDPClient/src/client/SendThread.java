package client;

import java.io.*;
import java.net.*;

//�����ı������������߳���
public class SendThread extends Thread{
	private InetAddress serverIP;
	private int serverPort;
	private DatagramSocket ssocket;
	public static String userName;
	
	//SendThread���๹�캯��
	public SendThread(InetAddress ia,int port)throws SocketException{
		this.serverIP = ia;
		this.serverPort = port;
		this.ssocket = new DatagramSocket();
	}
	
	//���SendThread�̵߳Ŀͻ�������
	public DatagramSocket getSocket(){
		return this.ssocket;
	}
	public void run(){
		try{
			BufferedReader userInput =new BufferedReader(new InputStreamReader(System.in));
			System.out.println("������Ҫ���͵���Ϣ��ÿ��һ�У��س�����һ�����룬bye����ͨѶ");
			//System.out.println("�������û�����");
			//userName=userInput.readLine();
			while(true){
				String msg = userInput.readLine();
				
				if(msg.equals("bye")){
					System.out.println("�������ѹرգ������������ı�");
					break;
				}
					
				byte[] data = msg.getBytes();
				
				//����Ŀ�ĵ�ַΪ�����������ݱ��İ�����
				DatagramPacket dgpOutput = new DatagramPacket(data,data.length,serverIP,serverPort);
				
				//�ͻ��˷������ݱ���������
				ssocket.send(dgpOutput);
				Thread.yield();
			}
		}catch(IOException e){
			e.printStackTrace();
		}
	}

}
