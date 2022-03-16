function solution(genres, plays) {
  const album = new Map();
  genres.forEach((genre, index) => {
    let data = album.get(genre) || { total: 0, songs: [] };
    data.total += plays[index];
    data.songs = [...data.songs, [index, plays[index]]]
      .sort((a, b) => b[1] - a[1])
      .slice(0, 2);
    album.set(genre, data);
  });
  const sortedAlbum = [...album]
    .sort((a, b) => b[1].total - a[1].total)
    .flatMap((genre) => genre[1].songs)
    .flatMap((song) => song[0]);

  return sortedAlbum;
}
