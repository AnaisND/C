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
    internal class FisaConsum
    {
        [BsonId]
        [BsonRepresentation(BsonType.ObjectId)]
        public string _id { get; set; }


        public string Nume_Produs { get; set; }
        public string Nume_Materie_Prima { get; set; }
        public int Cantitate { get; set; }

        /*public FisaConsum() 
        {
            Nume_Produs = string.Empty;
            Nume_Materie_Prima = string.Empty;
            Cantitate = 0;
        }

        public FisaConsum(string np, string nmp, int q)
        {
            Nume_Produs = np;
            Nume_Materie_Prima = nmp;
            Cantitate = q;
        }*/

        public override string ToString()
        {
            return this.Nume_Produs + " - " + this.Nume_Materie_Prima + " - " + this.Cantitate;
        }
    }
}
