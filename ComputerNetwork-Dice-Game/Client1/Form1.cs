using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Sockets;

namespace Client1
{
    public partial class Form1 : Form
    {
        TcpClient clientSocket;
        PictureBox[] p = new PictureBox[3];//picturebox陣列儲存骰子隨機變數對應之點數圖片
        int[] num = new int[7];//陣列儲存骰子隨機變數
        int t=0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)//initialize最初顯示的骰子圖片皆為點數1
        {
            p[1] = pictureBox1;
            p[2] = pictureBox2;
            pictureBox1.Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\1.jpeg");
            pictureBox2.Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\1.jpeg");
            timer1.Interval = 10;//週期為0.01秒
        }

        private void button1_Click(object sender, EventArgs e)//connet
        {
            clientSocket = new TcpClient();
            try
            {
                clientSocket.Connect("127.0.0.1", 8888);
            }
            catch (Exception ex)
            {
                label1.Text = "Sever not found";
                clientSocket = null;
                return;
            }
            label1.Text = "Connected";
        }

        private void button2_Click(object sender, EventArgs e)//send receive
        {
            if (clientSocket == null)
            {
                label1.Text = "Server is Off";
                return;
            }
            NetworkStream serverStream = clientSocket.GetStream();
            byte[] outStream = System.Text.Encoding.ASCII.GetBytes(textBox1.Text);
            serverStream.Write(outStream, 0, outStream.Length);
            serverStream.Flush();
            label1.Text = "Send: " + textBox1.Text;

            byte[] inStream = new byte[1000];
            serverStream.Read(inStream, 0, 100);
            string returndata = System.Text.Encoding.ASCII.GetString(inStream);
            label1.Text = "Recv:" + returndata;
        }

        private void button3_Click(object sender, EventArgs e)//start
        {
            timer1.Enabled = true;//計時器
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random r = new Random();//拉霸
            for(int i = 1; i <= 2; i++)
            {
                num[i] = r.Next(1, 6);
                if (num[i] == 1)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\1.jpeg");
                }
                else if (num[i] == 2)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\2.jpeg");
                }
                else if (num[i] == 3)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\3.jpeg");
                }
                else if (num[i] == 4)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\4.jpeg");
                }
                else if (num[i] == 5)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\5.jpeg");
                }
                else if (num[i] == 6)
                {
                    p[i].Image = Image.FromFile("C:\\Users\\miya\\OneDrive\\桌面\\NTPU\\大二\\電網實習\\Client1\\6.jpeg");
                }
            }
            t += 1;//跑20個週期共0.2秒
            if (t == 20)
            {
                int serverdice;
                int serverdice1;
                int serverdice2;
                int clientdice;
                int clientdice1 = num[1];
                int clientdice2 = num[2];
                serverdice1 = r.Next(1, 6);
                serverdice2 = r.Next(1, 6);
                serverdice = serverdice1 + serverdice2;
                clientdice = clientdice1 + clientdice2;
                label1.Text = "Computer " + serverdice1.ToString() + "+" + serverdice2.ToString() + "=" + serverdice.ToString();
                label2.Text = "Player   " + clientdice1.ToString() + "+" + clientdice2.ToString() + "=" + clientdice.ToString();
                if (clientdice > serverdice)
                {
                    label3.Text = "Player Win！";
                }
                else if (clientdice < serverdice)
                {
                    label3.Text = "Computer Win！";
                }
                else
                {
                    label3.Text = "Tie！";
                }
                if (clientSocket == null)
                {
                    label1.Text = "Server is Off";
                    return;
                }
                //回傳server的點數給server
                NetworkStream serverStream = clientSocket.GetStream();
                byte[] outStream = System.Text.Encoding.ASCII.GetBytes(label1.Text);
                serverStream.Write(outStream, 0, outStream.Length);
                serverStream.Flush();
                label1.Text = label1.Text;

                byte[] inStream = new byte[1000];
                serverStream.Read(inStream, 0, 100);
                string returndata = System.Text.Encoding.ASCII.GetString(inStream);
                timer1.Enabled = false;
                t = 0;
            }
        }
    }
}