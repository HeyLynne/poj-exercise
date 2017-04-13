package client;

import java.io.IOException;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

//���࣬�����ͻ��׽��֣������ͻ���
public class UDPClient {
	public static void main(String[] args) throws SocketException
	{
		//ָ����������IP��ַ
		String remoteHost = "localhost";
		//ָ���������Ķ˿ں�
		int remotePort = 8000;
		//�����ͻ�DatagramSocket������ͻ�������һ��UDP�˿ڰ�
		DatagramSocket dgSocket = new DatagramSocket();
		
		//������������ı�
		try{
			//��ȡ������IP��ַ
			InetAddress remoteIP = InetAddress.getByName(remoteHost);
			
			//����SendThread�������������ı��߳�
			SendThread sender = new SendThread(remoteIP,remotePort);
			sender.start();
			
			//����ReceiveThread�������������ı�
			ReceiveThread receiver  = new ReceiveThread(sender.getSocket());
			receiver.start();		
		}catch(IOException e){
			e.printStackTrace();
		}finally{
			dgSocket.close();
		}
	}
	

}
