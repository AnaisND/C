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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string n = textBox1.Text;
            string dis = textBox2.Text;
            DateTime di;
            DateTime.TryParse(dis, out di);
            string dts = textBox3.Text;
            DateTime dt;
            DateTime.TryParse(dts, out dt);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "LotFabricatie";

            var productMongo = new LotFabricatieMongo(connectionString, databaseName, collectionName);

            var Lotfabricatie = new LotFabricatie
            {
                Nume_Produs = n,
                DataIncepere = di,
                DataTerminare = dt
            };
            productMongo.AddFabricatie(Lotfabricatie, connectionString, databaseName, collectionName);

            textBox1.Clear(); textBox2.Clear(); textBox3.Clear();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string i = textBox4.Text;
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "LotFabricatie";
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            productMongo.RemoveProductById(i, connectionString, databaseName, collectionName);
            textBox4.Clear();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string i = textBox5.Text;
            string n = textBox6.Text;
            string dis = textBox7.Text;
            DateTime di;
            DateTime.TryParse(dis, out di);
            string dts = textBox8.Text;
            DateTime dt;
            DateTime.TryParse(dts, out dt);
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "LotFabricatie";
            var productMongo = new LotFabricatieMongo(connectionString, databaseName, collectionName);

            productMongo.UpdateFabricatieById(i,n,di,dt, connectionString, databaseName, collectionName);

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
