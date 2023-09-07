using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace PAWProiectFinal
{
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
            Controls.Add(chart1);
        }

        private void DisplayPieChart(List<int> data)
        {
            chart1.Series.Clear();
            chart1.ChartAreas.Clear();

            Series series = new Series("PieChartProduse");
            ChartArea chartArea = new ChartArea("DataChartArea");

            series.ChartType = SeriesChartType.Pie;
            series.IsValueShownAsLabel = true;

            for (int i = 0; i < data.Count; i++)
            {
                series.Points.AddXY("Produs " + (i + 1), data[i]);
            }

            chart1.Series.Add(series);
            chart1.ChartAreas.Add(chartArea);

            chart1.Refresh();
        }

        private void DisplayBarGraph(List<int> data)
        {
            chart1.Series.Clear();
            chart1.ChartAreas.Clear();

            Series series = new Series("BarGraphProduse");
            ChartArea chartArea = new ChartArea("DataChartArea");

            series.ChartType = SeriesChartType.Column;
            series.IsValueShownAsLabel = true;

            for (int i = 0; i < data.Count; i++)
            {
                series.Points.AddXY("Produs " + (i + 1), data[i]);
            }

            chart1.Series.Add(series);
            chart1.ChartAreas.Add(chartArea);

            chart1.Refresh();
        }

        private void DisplayLineGraph(List<int> data)
        {
            chart1.Series.Clear();
            chart1.ChartAreas.Clear();

            Series series = new Series("LineGraphProduse");
            ChartArea chartArea = new ChartArea("DataChartArea");

            series.ChartType = SeriesChartType.Line;
            series.IsValueShownAsLabel = true;

            for (int i = 0; i < data.Count; i++)
            {
                series.Points.AddXY("Produs " + (i + 1), data[i]);
            }

            chart1.Series.Add(series);
            chart1.ChartAreas.Add(chartArea);

            chart1.Refresh();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";
            List<Produs> Produse = new List<Produs>();
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            Produse = productMongo.GetAllProducts(connectionString, databaseName, collectionName);
            List<int> Valori = new List<int>();
            for (int i = 0; i < Produse.Count; i++)
            {
                Valori.Add(Produse[i].Valoare());
            }
            DisplayPieChart(Valori);
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";
            List<Produs> Produse = new List<Produs>();
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            Produse = productMongo.GetAllProducts(connectionString, databaseName, collectionName);
            List<int> Valori = new List<int>();
            for (int i = 0; i < Produse.Count; i++)
            {
                Valori.Add(Produse[i].Valoare());
            }
            DisplayBarGraph(Valori);
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            var connectionString = "mongodb+srv://proiectpaw1234:qjLMoQIlCM5YFYEC@cluster0.acvaqfz.mongodb.net/test";
            var databaseName = "PAW";
            var collectionName = "Produs";
            List<Produs> Produse = new List<Produs>();
            var productMongo = new ProductMongo(connectionString, databaseName, collectionName);
            Produse = productMongo.GetAllProducts(connectionString, databaseName, collectionName);
            List<int> Valori = new List<int>();
            for (int i = 0; i < Produse.Count; i++)
            {
                Valori.Add(Produse[i].Valoare());
            }
            DisplayLineGraph(Valori);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            f2.Show();
            this.Visible = false;
        }
    }
}