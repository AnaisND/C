using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Bson;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAWProiectFinal
{
    internal class LotFabricatie
    {
        [BsonId]
        [BsonRepresentation(BsonType.ObjectId)]
        public string _id { get; set; }


        public string Nume_Produs { get; set; }
        public DateTime DataIncepere {  get; set; }
        public DateTime DataTerminare { get; set; }

        /*public LotFabricatie() 
        {
            NumeProdus = string.Empty;
            DataIncepere = DateTime.MinValue;
            DataTerminare = DateTime.MinValue;
        }

        public LotFabricatie(string nume, DateTime di, DateTime dt)
        {
            NumeProdus = nume;
            DataIncepere = di;
            DataTerminare = dt;
        }*/

        public override string ToString()
        {
            return this.Nume_Produs + " - Incepe la:" + this.DataIncepere + " - Se termina la:" + this.DataTerminare;
        }
    }
}
