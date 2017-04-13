package client;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

//主类，创建客户套接字，启动客户端
public class UDPClient {
	public static void main(String[] args) throws SocketException
	{
		//指定服务器的IP地址
		String remoteHost = "localhost";
		//指定服务器的端口号
		int remotePort = 8000;
		//创建客户DatagramSocket对象，与客户的任意一个UDP端口绑定
		DatagramSocket dgSocket = new DatagramSocket();
		
		//与服务器传输文本
		try{
			//获取服务器IP地址
			InetAddress remoteIP = InetAddress.getByName(remoteHost);
			
			//创建SendThread对象，启动发送文本线程
			SendThread sender = new SendThread(remoteIP,remotePort);
			sender.start();
			
			//创建ReceiveThread对象，启动接收文本
			ReceiveThread receiver  = new ReceiveThread(sender.getSocket());
			receiver.start();		
		}catch(IOException e){
			e.printStackTrace();
		}finally{
			dgSocket.close();
		}
	}
	

}
