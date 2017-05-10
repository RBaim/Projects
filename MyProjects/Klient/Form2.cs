using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
namespace Klient
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text != "" && textBox1.Text != " " && textBox2.Text != "" && textBox2.Text != " ")
                {
                    DirectoryInfo data = new DirectoryInfo("Client_info");
                    data.Create();
                    var sw = new StreamWriter(@"Client_info/info_data.txt");
                    sw.WriteLine(textBox1.Text + ":" + textBox2.Text);
                    sw.Close();
                    this.Hide();
                    Application.Restart();
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show("Ошибка:" + ex.Message);
            }
        }
    }
}
