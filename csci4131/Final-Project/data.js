// this package behaves just like the mysql one, but uses async await instead of callbacks.
const mysql = require(`mysql-await`); // npm install mysql-await

// first -- I want a connection pool: https://www.npmjs.com/package/mysql#pooling-connections
// this is used a bit differently, but I think it's just better -- especially if server is doing heavy work.
var connPool = mysql.createPool({
  connectionLimit: 5, // it's a shared resource, let's not go nuts.
  host: "localhost",// this will work
  user: "C4131F23U204",
  database: "C4131F23U204",
  password: "41666",
});


async function addUser(data) {
  await connPool.awaitQuery("INSERT INTO Users (user_name, password) VALUES (?, ?);", [data.username, data.password]);
}

async function login(data) {
  const query = 'SELECT * FROM Users WHERE user_name = ?';
  const result = await connPool.awaitQuery(query, [data.username]);
  return result;
}


async function getPosts(data) {
  let query = `
  SELECT 
    Posts.id AS post_id,
    Users.user_name,
    Posts.creator_id,
    Posts.content,
    COUNT(CASE WHEN Likes.positive = TRUE THEN 1 END) AS likes_count,
    COUNT(CASE WHEN Likes.positive = FALSE THEN 1 END) AS dislikes_count`;
  if (data.user_id != -1) {
    query += `
      ,MAX(CASE WHEN Likes.positive = TRUE AND Likes.user_id = ? THEN 1 ELSE 0 END) AS liked,
      MAX(CASE WHEN Likes.positive = FALSE AND Likes.user_id = ? THEN 1 ELSE 0 END) AS disliked
      `;

  }
  query += `
      FROM
        Posts
        LEFT JOIN Likes ON Posts.id = Likes.post_id
        LEFT JOIN Users ON Posts.creator_id = Users.id
        GROUP BY
        Posts.id, Posts.creator_id, Posts.content
      `;
  if (data.sortBy == 0) {
    query += `ORDER BY Posts.id DESC`;
  } else if (data.sortBy == 1) {
    query += `ORDER BY likes_count DESC, dislikes_count ASC`;
  } else if (data.sortBy == 2) {
    query += `ORDER BY dislikes_count DESC, likes_count ASC`;
  }
  query += `
    LIMIT 5
    `;
  if (data.page >= 1) {
    query += `OFFSET ?`
  }
  if (data.user_id != -1) {
    return await connPool.awaitQuery(query, [data.user_id, data.user_id, (data.page * 5)]);
  } else {
    return await connPool.awaitQuery(query, [(data.page * 5)]);
  }
}

async function addPost(data) {
  query = 'INSERT INTO Posts (creator_id, content) VALUES (?, ?);'
  return await connPool.awaitQuery(query, [data.user_id, data.content]);
}

async function editPost(data) {
  const query = 'UPDATE Posts SET content = ? WHERE creator_id = ? AND id = ?;';
  return await connPool.awaitQuery(query, [data.content, data.user_id, data.post_id]);
}

async function deletePost(data) {
  const query1 = 'DELETE Likes FROM Likes JOIN Posts ON Likes.post_id = Posts.id WHERE Posts.creator_id = ? AND Posts.id = ?;';
  const query2 = 'DELETE FROM Posts WHERE creator_id = ? AND id = ?;';

  await connPool.awaitQuery(query1, [data.user_id, data.post_id]);
  return await connPool.awaitQuery(query2, [data.user_id, data.post_id]);
}

async function likeExists(data) {
  const query = `
    SELECT 
      CASE 
        WHEN EXISTS (
          SELECT 1
          FROM Likes
          WHERE Likes.user_id = ? AND Likes.post_id = ?
        ) THEN 'true'
        ELSE 'false'
      END AS like_exists,
      positive
    FROM Likes
    WHERE Likes.user_id = ? AND Likes.post_id = ?;`;

  const result = await connPool.awaitQuery(query, [data.user_id, data.post_id, data.user_id, data.post_id]);
  if (result.length > 0) {
    return {
      exists: result[0].like_exists === 'true',
      positive: result[0].positive
    };
  } else {
    return {
      exists: false,
      positive: null
    };
  }
}

async function like(data) {
  const query = `
    INSERT INTO Likes (user_id, post_id, positive) values (?, ?, ?)
    ON DUPLICATE KEY UPDATE positive = ?`;

  const result = await connPool.awaitQuery(query, [data.user_id, data.post_id, data.positive, data.positive]);
  return result;
}

async function unlike(data) {
  const query = 'DELETE FROM Likes WHERE Likes.post_id = ? AND Likes.user_id = ?';
  await connPool.awaitQuery(query, [data.post_id, data.user_id]);
  return 1;
}



module.exports = { addUser, getPosts, login, like, unlike, addPost, editPost, deletePost, likeExists }