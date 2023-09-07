using MySqlConnector;
using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Mail;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PAWProiectFinal
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string n = textBox1.Text;
            int q = Int32.Parse(textBox2.Text);
            int p = Int32.Parse(textBox3.Text);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";

            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);

            var newProduct = new Produs
            {
                Nume = n,
                Cantitate = q,
                Pret = p
            };
            productMongo.AddProduct(newProduct, connectionString, databaseName, collectionName);

            textBox1.Clear(); textBox2.Clear(); textBox3.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string i = textBox4.Text;
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            productMongo.RemoveProductById(i, connectionString, databaseName, collectionName);
            textBox4.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string i = textBox5.Text;
            string n = textBox6.Text;
            int q = Int32.Parse(textBox7.Text);
            int p = Int32.Parse(textBox8.Text);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            productMongo.UpdateProductById(i,n,q,p,connectionString,databaseName,collectionName);
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
