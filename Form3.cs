using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace PAWProiectFinal
{
    public partial class Form3 : Form
    {
        BindingSource bindingSource = new BindingSource();
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";

            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            var products = productMongo.GetProducts();

            dataGridView1.DataSource = products;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            this.Visible = false;
        }
    }
}
