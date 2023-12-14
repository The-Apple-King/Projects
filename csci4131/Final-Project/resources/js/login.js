document.addEventListener('DOMContentLoaded', function () {
  const openPopupButton = document.getElementById('createNewAccount');
  const popupContent = document.getElementById('createAccount');

  openPopupButton.addEventListener('click', function () {
    popupContent.style.display = 'block';
  });

  const cancel = document.getElementById('cancel');
  cancel.addEventListener('click', function () {
    popupContent.style.display = 'none';
  });
});
