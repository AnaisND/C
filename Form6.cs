using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PAWProiectFinal
{
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string np = textBox1.Text;
            string nmp = textBox2.Text;
            int q = Int32.Parse(textBox3.Text);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "FisaConsum";

            var productMongo = new FisaConsumMongo(connectionString, databaseName, collectionName);

            var newFisaConsum = new FisaConsum
            {
                Nume_Produs = np,
                Nume_Materie_Prima = nmp,
                Cantitate = q
            };
            productMongo.AddConsum(newFisaConsum, connectionString, databaseName, collectionName);

            textBox1.Clear(); textBox2.Clear(); textBox3.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string i = textBox4.Text;
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "FisaConsum";
            var productMongo = new FisaConsumMongo(connectionString, databaseName, collectionName);
            productMongo.RemoveConsumById(i, connectionString, databaseName, collectionName);
            textBox4.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string i = textBox5.Text;
            string np = textBox6.Text;
            string nmp = textBox7.Text;
            int q = Int32.Parse(textBox8.Text);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "FisaConsum";
            var productMongo = new FisaConsumMongo(connectionString, databaseName, collectionName);
            productMongo.UpdateConsumById(i, np, nmp, q, connectionString, databaseName, collectionName);
            textBox5.Clear(); textBox6.Clear(); textBox7.Clear(); textBox8.Clear();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            this.Visible = false;
        }
    }
}
