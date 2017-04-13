package client;

import java.io.*;
import java.net.*;

//接收文本的线程
public class ReceiveThread extends Thread{
	DatagramSocket rsocket;
	
	public ReceiveThread(DatagramSocket dgSocket){
		rsocket = dgSocket; 
	}
	
	public void run(){
		byte[] buffer = new byte[65507];
		
		while(true){
			//创建接受文本为DatagramPacket对象
			DatagramPacket dgp = new DatagramPacket(buffer,buffer.length);
			
			try{
				//接受服务器返回的文本，存入上面定义的dgp对象
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
