package client;

import java.io.*;
import java.net.*;

//�����ı����߳�
public class ReceiveThread extends Thread{
	DatagramSocket rsocket;
	
	public ReceiveThread(DatagramSocket dgSocket){
		rsocket = dgSocket; 
	}
	
	public void run(){
		byte[] buffer = new byte[65507];
		
		while(true){
			//���������ı�ΪDatagramPacket����
			DatagramPacket dgp = new DatagramPacket(buffer,buffer.length);
			
			try{
				//���ܷ��������ص��ı����������涨���dgp����
				rsocket.receive(dgp);
				String msg = new String(dgp.getData(),0,dgp.getLength());
				System.out.println(msg);
				Thread.yield();
			}catch(IOException e){
				e.printStackTrace();
			}
		}
	}
}
