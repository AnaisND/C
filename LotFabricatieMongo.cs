using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Core.Configuration;
using MySqlX.XDevAPI;
using Org.BouncyCastle.Utilities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAWProiectFinal
{
    internal class LotFabricatieMongo
    {
        private readonly IMongoCollection<LotFabricatie> _collection;

        public LotFabricatieMongo(string connectionString, string databaseName, string collectionName)
        {
            var client = new MongoClient(connectionString);
            var database = client.GetDatabase(databaseName);
            _collection = database.GetCollection<LotFabricatie>(collectionName);
        }

        public List<LotFabricatie> GetProducts()
        {
            var products = _collection.Find(_ => true).ToList();
            return products;
        }

        public void AddFabricatie(LotFabricatie product, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var document = new BsonDocument
        {
            { "Nume_Produs", product.Nume_Produs },
            { "DataIncepere", product.DataIncepere },
            { "DataTerminare", product.DataTerminare }
        };

            collection.InsertOne(document);
        }

        public void RemoveFabricatieById(string id, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));

            collection.DeleteOne(filter);
        }

        public void UpdateFabricatieById(string id, string nume, DateTime di, DateTime dt, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));
            var update = Builders<BsonDocument>.Update
                .Set("Nume_Produs", nume)
                .Set("DataIncepere", di)
                .Set("DataTerminare", dt);

            collection.UpdateOne(filter, update);
        }

        public List<LotFabricatie> GetAllFabricatii(string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var documents = collection.Find(new BsonDocument()).ToList();
            var productList = new List<LotFabricatie>();

            foreach (var document in documents)
            {
                var product = new LotFabricatie
                {
                    _id = document["_id"].ToString(),
                    Nume_Produs = document["Nume_Produs"].ToString(),
                    DataIncepere = DateTime.Parse(document["DataIncepere"].ToString()),
                    DataTerminare = DateTime.Parse(document["DataTerminare"].ToString())
                };

                productList.Add(product);
            }

            return productList;
        }
    }
}
