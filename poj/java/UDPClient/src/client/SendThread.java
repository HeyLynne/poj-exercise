package client;

import java.io.*;
import java.net.*;

//发送文本给服务器的线程类
public class SendThread extends Thread{
	private InetAddress serverIP;
	private int serverPort;
	private DatagramSocket ssocket;
	public static String userName;
	
	//SendThread的类构造函数
	public SendThread(InetAddress ia,int port)throws SocketException{
		this.serverIP = ia;
		this.serverPort = port;
		this.ssocket = new DatagramSocket();
	}
	
	//获得SendThread线程的客户端套字
	public DatagramSocket getSocket(){
		return this.ssocket;
	}
	public void run(){
		try{
			BufferedReader userInput =new BufferedReader(new InputStreamReader(System.in));
			System.out.println("请输入要发送的信息，每次一行，回车结束一次输入，bye结束通讯");
			//System.out.println("请输入用户名：");
			//userName=userInput.readLine();
			while(true){
				String msg = userInput.readLine();
				
				if(msg.equals("bye")){
					System.out.println("服务器已关闭，请勿再输入文本");
					break;
				}
					
				byte[] data = msg.getBytes();
				
				//创建目的地址为服务器的数据报文包对象
				DatagramPacket dgpOutput = new DatagramPacket(data,data.length,serverIP,serverPort);
				
				//客户端发送数据报给服务器
				ssocket.send(dgpOutput);
				Thread.yield();
			}
		}catch(IOException e){
			e.printStackTrace();
		}
	}

}
