using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net;
using System.Net.Sockets;
using System.IO;
using System.Threading;

namespace Klient
{
    public partial class Form1 : Form
    {
        static private Socket Client;
        private IPAddress ip = null;
        private int port = 0;
        private Thread th;
        public Form1()
        {
            InitializeComponent();
            richTextBox2.Enabled = false;
            button1.Enabled = false;
            try
            {
                var sr = new StreamReader(@"Client_info/info_data.txt");
                string buffer = sr.ReadToEnd();
                sr.Close();
                string[] connect_info = buffer.Split(':');
                ip = IPAddress.Parse(connect_info[0]);
                port = int.Parse(connect_info[1]);
                label5.ForeColor = Color.Green;
                label5.Text = "Настройки сервера\nIp адрес: " + connect_info[0] + "\nПорт: " + connect_info[1];
            }
            catch (Exception ex)
            {
                label5.ForeColor = Color.Red;
                label5.Text = "Настройки не найдены!";
                Form2 form = new Form2();
                form.Show();
            }
        }

        private void настройкиToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form2 form = new Form2();
            form.Show();
        }
        void SendMessage(string message)
        {
            if (message != " " && message != "" && richTextBox2.Text != " " && richTextBox2.Text != "")
            {
                byte[] buffer = new byte[1024];
                buffer = Encoding.UTF8.GetBytes(message);
                Client.Send(buffer);
            }
        }
        void ReavMessage()
        {
            byte[] buffer = new byte[1024];
            for (int i = 0; i < buffer.Length; i++)
            {
                buffer[i] = 0;
            }
            for (;;)
            {
                try
                {
                    Client.Receive(buffer);
                    string message = Encoding.UTF8.GetString(buffer);
                    int count = message.LastIndexOf("\r");
                    if (count == -1)
                    {
                        continue;
                    }
                    string Clear_Message = "";
                    for (int i = 0; i < count; i++)
                    {
                        Clear_Message += message[i];
                    }
                    for (int i = 0; i < buffer.Length; i++)
                    {
                        buffer[i] = 0;
                    }
                    this.Invoke((MethodInvoker)delegate ()
                    {
                        richTextBox1.AppendText(Clear_Message);
                        richTextBox1.SelectionStart = richTextBox1.Text.Length;
                        richTextBox1.ScrollToCaret();
                    });
                }
                catch (Exception ex)
                {

                }
            }
        }
        void avt()
        {
            if (textBox1.Text != "" && textBox1.Text != " ")
            {
                richTextBox2.Enabled = true;
                textBox1.Enabled = false;
                richTextBox2.Focus();
                button1.Enabled = true;
                button2.Enabled = false;
                Client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                if (ip != null)
                {
                    Client.Connect(ip, port);
                    th = new Thread(delegate () { ReavMessage(); });
                    th.Start();
                }
            }
            else
            {
                MessageBox.Show("Ник должен быть непустым");
            }
        }
        void reavt()
        {
            textBox1.Clear();
            textBox1.Enabled = true;
            textBox1.Focus();
            button1.Enabled = false;
            button2.Enabled = true;
            richTextBox2.Enabled = false;
            if (th != null)
                th.Abort();
            if (Client != null)
            {
                Client.Close();
            }
            richTextBox1.AppendText("\nВы отключены\n");
        }
        private void button2_Click(object sender, EventArgs e)
        {
            avt();
        }
        private void авторToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("  by R.baim\n  2017 год");
        }

        private void выходToolStripMenuItem_Click(object sender, EventArgs e)
        {
            reavt();
            Application.Exit();
        }

        private void richTextBox2_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                richTextBox2.Text = richTextBox2.Text.Remove(richTextBox2.Text.Length-1);
                SendMessage("\n" + textBox1.Text + ": " + richTextBox2.Text + "\r");
                richTextBox2.Clear();
            }
        }

        private void textBox1_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (e.KeyChar == '\r')
            {
                avt();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            reavt();
        }

        private void richTextBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
