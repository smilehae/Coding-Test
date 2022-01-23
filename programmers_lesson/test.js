function solution(genres, plays) {
    var answer = [];
    const allGenres = new Set();
    const totalGenre={};
    for(let i=0;i<genres.length;i++){
        totalGenre[genres[i]] = 0;
        if(!allGenres.has(genres[i])){
            allGenres.add(genres[i]);
        }
    }
    for(let i=0;i<genres.length;i++){
        totalGenre[genres[i]] += plays[i];
    }
    
    console.log(allGenres);
    
    
    return answer;
}