let editPostId;

document.addEventListener('DOMContentLoaded', function () {
  const createPost = document.getElementById('postButton');
  const create = document.getElementById('createPost');

  createPost.addEventListener('click', function () {
    create.style.display = 'block';
  });

  const editPost = document.getElementById("edit");
  if (editPost) {
    editPost.addEventListener('click', function () {
      edit.style.display = 'inline';
    });
  }

  const dropdown = document.getElementById("dropdown");
  dropdown.addEventListener("change", function () {
    var sortBy = dropdown.selectedIndex;
    var page = document.getElementsByClassName("page-number").textContent;
    var newUrl = `/main?page=0&sortBy=${sortBy}`;
    window.location.href = newUrl;
  });

  // when the page is loaded check to make sure we have the right dropdown value selected
  var currentUrl = window.location.href;
  var sortByMatch = currentUrl.match(/[?&]sortBy=(\d+)/);
  if (sortByMatch) {
    dropdown.value = sortByMatch[1];
  }
});

function closePopup(id) {
  const popup = document.getElementById(id);
  popup.querySelector("textarea").value = '';
  popup.style.display = 'none';
}

function editPost(post_id, content) {
  const edit = document.getElementById('editPost');
  edit.style.display = 'block';
  edit.querySelector("textarea").value = content;
  editPostId = post_id;
  document.getElementById('editPostForm').post_id.value = editPostId;
}

function updateCount(positive, liked) {
  let query;
  if (positive) {
    query = ".likes"
  } else {
    query = ".dislikes";
  }
  const likesDiv = document.querySelector(query);
  const currentLikesCount = parseInt(likesDiv.textContent) || 0;
  if (liked) {
    likesDiv.textContent = currentLikesCount + 1
  } else {
    likesDiv.textContent = currentLikesCount - 1
  }
}

let isLikeFunctionRunning = false;

async function like(positive, post_id) {
  if (isLikeFunctionRunning) {
    return;
  }

  isLikeFunctionRunning = true;

  try {
    const options = {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ positive: positive, post_id: post_id }),
    };

    const likeExists = await fetch("/likeExists", options);
    if (likeExists.redirected) {
      window.location.href = likeExists.url;
      return;
    }
    const result = await likeExists.json(); // Parse JSON response
    const exists = result.liked.exists;
    const positiveValue = result.liked.positive;

    let response;
    if (!exists) {// if we haven't interacted yet
      response = await fetch("/like", options); // like or dislike the first time

      if (response.redirected) {
        window.location.href = response.url;
      } else {
        updateCount(positive, !exists); // remove the like locally
      }
    } else { // we interacted already
      response = await fetch("/unlike", options); // delete the like

      if (response.redirected) {
        window.location.href = response.url;
      } else {
        updateCount(positiveValue, !exists); // remove the like locally
        if (positive != positiveValue) {
          response = await fetch("/like", options); // like or dislike the first time
          updateCount(positive, exists)
        }
      }
    }
  } catch (error) {
    console.error("Error in like function:", error);
  } finally {
    isLikeFunctionRunning = false;
  }
}


async function deletePost(user_id, post_id) {
  const options = {
    method: 'DELETE',
    headers: {
      'Content-Type': 'application/json',
    },
    body: JSON.stringify({ user_id: user_id, post_id: post_id }),
  };
  const response = await fetch("/deletePost", options);
  if (response.redirected) {
    window.location.href = response.url;
  }
}


